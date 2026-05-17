# Part 1
## 1.
- Library
- Book
    - PrintedBook
    - EBook
- Member
- Librarian
- Loan
## 2.
- Library:
    - addBook(b: Book): bool
- Book:
    - title: sting
    - isbn: sting
    - available: bool
    - borrow(): void
- PrintedBook:
    - printLocation(): void
- EBook:
    - download(): void
- Member:
    - borrow(b: Book): void
- Librarian:
    - salary: double
    - register(m: Member): void
- Loan:
    - close(): void
## 3.
- PrintedBook inherits from Book
- EBook inherits from Book
- Librarian inherits from Member
## 4.
- Library is composed of Book
- Loan is composed of Book (des aber dumm)
- Library -- Member -> Aggregation
- Library is associated with Librarian
- Member is associated with Loan

# Part 2
- Correct:
    - Inheritance between Book and PrintedBook/Ebook
        - Both PrintedBook and Ebook are a type of Book. An abstraction makes sense in thin case, bekause they share some properties, like isb, title, etc.
    - Aggregation of Member and Library
        - Library Members make up the Library, but can exist independently.
    - Composition between Book and Library
        - If modeled this way, books can only exist in librarys. If this is what you want, composition is correct. Every action with the Book has to occur using the library as a "middle man"
- Questionable
    - Inheritance between Libraian and Member
        - In the modeled case, Librarians always have to be Members. This is not always the case in reality, but can work.
        - Better: Adittional Class: Person
    - Association between Library and Librarian
        - Works, but Aggregation would be better. Librarians are PART of the Library like Members.
    - Association between Member and Loan
        - Association works here, but I would prefer Aggregation, because Loans belong to the Members. I wouldn't use Composition, so that loans can be transferred between members.
- Incorrect
    - Composition between Book and Loan
        - Books are already part of Library through composition. There can only always be one Composition relationship. Using an Aggregation in Loan (with pointers to the library's books) is better here.
The inheritance between Librarian and Member is questionable as explained above.
The Design also doesn't preserve encapsulaition very well. For example are all Attributes of Book publicly accessible. Also the librarians salary °o°