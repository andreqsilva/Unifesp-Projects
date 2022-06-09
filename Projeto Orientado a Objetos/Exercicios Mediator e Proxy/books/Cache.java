package books;
import java.util.ArrayList;

public class Cache implements Library {
	private ArrayList<Book> bookList = new ArrayList<Book>();
	
	public void addBook(Book book) {
		for(Book b : bookList) {
			if(b == book) {
				System.out.println("Livro já inserido");
				return;
			}
		}
		bookList.add(book);
	}
	
	public ArrayList<Book> getBookList() {
		return bookList;
	}
	
	public boolean searchBook(String title) {
		for(Book b : bookList) {
			if(b.getTitle() == title) {
				return true;
			}
		}
		return false;
	}
	
	@Override
	public Book getBook(String title) {
		for(Book b : bookList) {
			if(b.getTitle() == title) {
				return b;
			}
		}
		return null;
	}
	
}
