#Write a Pythonprogram for department library which has N books

# Department library class
class DepartmentLibrary:
    def __init__(self, books):
        self.books = books
    
    # Delete duplicate entries
    def delete_duplicates(self):
        self.books = list(set(self.books))
    
    # Display books in ascending order based on cost
    def display_books_ascending(self):
        self.books.sort(key=lambda x: x[1])
        for book in self.books:
            print(book[0], book[1])
    
    # Count number of books with cost more than 500
    def count_costly_books(self):
        count = 0
        for book in self.books:
            if book[1] > 500:
                count += 1
        return count
    
    # Copy books with cost less than 500 to a new list
    def copy_affordable_books(self):
        affordable_books = []
        for book in self.books:
            if book[1] < 500:
                affordable_books.append(book)
        return affordable_books
# Create an object of the DepartmentLibrary class
library = DepartmentLibrary([('Book1', 200), ('Book2', 300), ('Book3', 400), ('Book4', 500), ('Book5', 600)])

# Delete duplicate entries
library.delete_duplicates()

# Display books in ascending order based on cost
library.display_books_ascending()

# Count number of books with cost more than 500
count = library.count_costly_books()
print(count)

# Copy books with cost less than 500 to a new list
affordable_books = library.copy_affordable_books()
print(affordable_books)