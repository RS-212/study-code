/**
 * @file sensor.c
 * 
 * @brief Program to analyse sensor data from files
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_SIZE 3000
#define INTERVALS 300
#define SENSOR_1_THRESHOLD 0.8
#define SENSOR_2_THRESHOLD 0.7
#define SENSOR_1_PATH "../sensor1.txt"
#define SENSOR_2_PATH "../sensor2.txt"

typedef struct
{
    float time;
    double probability;
} SensorData;

typedef struct 
{
    int id;
    double threshold;
    SensorData data[SAMPLE_SIZE];
    int object_detection[SAMPLE_SIZE];
} Sensor;

typedef struct
{
    float start_time;
    float end_time;
} Interval;

/**
 * @brief Opens sensor file and stores contents so Sensor struct
 * 
 * @param[out] sensor_struct Sensor struct to store the data from the file in
 * @param[in] filepath Path to the sensor file
 * @param[in] threshold Threshold for object detection (if probability > threshold -> objects)
 * 
 * @return 1 if successful, 0 if unsuccessful
 */
int store_sensor_data(Sensor *sensor, char *path)
{
    // Open sensor file
    FILE *sensor_file = fopen(path, "r");
    if (sensor_file == NULL)
    {
        printf("Failed to open sensor file! Check the paths...\n");
        return -1;
    }

    // Write sensor data from file to struct
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        float *time = &(sensor->data[i].time);
        double *probability = &(sensor->data[i].probability);

        if (fscanf(sensor_file, "%f %lf", time, probability) != 2)
        {
            printf("Incorrect file format or insufficient data! Stopping Program.\n");
            fclose(sensor_file);
            return -1;
        }

        // Update object_detection based on data
        sensor->object_detection[i] = (*probability > sensor->threshold) ? 1 : 0;

        //printf("== %d ==\ntime: %f, probability: %lf, detection: %d\n\n", i, *time, *probability, sensor->object_detection[i]);
    }

    // Close file 
    if (fclose(sensor_file) == -1)
    {
        printf("Failed to close file °o°");
        return -1;
    }
    return 1;
}

/**
 * @brief Stores interval start and end times for sensor data
 * 
 * @param[out] intervals Array, that stores the different detection intervals
 * @param[in] sensor Sensor data
 */
void determine_intervals(Interval interval[], Sensor *sensor)
{
    int detection = 0;
    int interval_index = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        // Check if detection changes from 0 to 1 -> start of an interval
        if ((detection == 0) && (sensor->object_detection[i] == 1))
        {
            detection = 1;
            interval[interval_index].start_time = sensor->data[i].time;
        }
        // Check if detection changes from 1 to 0 -> end of an interval
        if ((detection == 1) && (sensor->object_detection[i] == 0))
        {
            detection = 0;
            interval[interval_index].end_time = sensor->data[i].time;
            interval_index++;
        }
    }
    // If file ends before detection, end interval at end of file
    if (detection == 1)
    {
        interval[interval_index].end_time = sensor->data[SAMPLE_SIZE-1].time;
    }
}

void fusing_sensors(Sensor *sensor1, Sensor *sensor2, Sensor *fused)
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        fused->data[i].time = sensor1->data[i].time;
        fused->object_detection[i] = sensor1->object_detection[i] && sensor2->object_detection[i];
    }
}

/**
 * @brief Print detections, break after seeing first -1
 * 
 * @param[in] detection_intervals array of size INTERVALS with -1 as default values
 */
void print_detections(Interval intervals[])
{
    for (int i = 0; i < INTERVALS; i++)
    {
        if (intervals[i].start_time == -1)
        {
            break;
        }
        printf("Start: %.2f s End: %.2f s ", intervals[i].start_time, intervals[i].end_time);
    }
    printf("\n");
}

int main()
{
    Sensor sensor1;
    Sensor sensor2;

    sensor1.id = 0;
    sensor2.id = 1;

    sensor1.threshold = SENSOR_1_THRESHOLD;
    sensor2.threshold = SENSOR_2_THRESHOLD;

    /* Alternativ: (da id und threshold die ersten 2 Elemente des Structs sind)
    Sensor sensor1 = {0, SENSOR_1_THRESHOLD};
    Sensor sensor2 = {1, SENSOR_2_THRESHOLD};
    */

    if (store_sensor_data(&sensor1, SENSOR_1_PATH) < 0)
    {
        return -1;
    }
    if (store_sensor_data(&sensor2, SENSOR_2_PATH) < 0)
    {
        return -1;
    }
    
    Sensor fused = {2, -1};
    fusing_sensors(&sensor1, &sensor2, &fused);

    // Determine start and end times for each detection interval
    Interval detections_sensor1[INTERVALS];
    Interval detections_sensor2[INTERVALS];
    Interval overlap[INTERVALS];

    // Initialize all with -1 as invalid value
    for (int i = 0; i < INTERVALS; i++)
    {
        detections_sensor1[i].start_time = -1;
        detections_sensor1[i].end_time = -1;

        detections_sensor2[i].start_time = -1;
        detections_sensor2[i].end_time = -1;

        overlap[i].start_time = -1;
        overlap[i].end_time = -1;
    }
    
    // Store valid interval values; the rest stays -1
    determine_intervals(detections_sensor1, &sensor1);
    determine_intervals(detections_sensor2, &sensor2);
    determine_intervals(overlap, &fused);

    // Print detection results
    printf("--- Object Detection Results ---\n");
    printf("\nSensor 1 detections: ");
    print_detections(detections_sensor1);
    printf("\nSensor 2 detections: ");
    print_detections(detections_sensor2);
    printf("\nFused signal (both sensors): ");
    print_detections(overlap);

    return 0;
}