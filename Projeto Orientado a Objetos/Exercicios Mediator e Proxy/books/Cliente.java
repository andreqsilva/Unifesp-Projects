package books;

public class Cliente {
	public static void main(String[] args) {
		Book book1 = new Book("Animal Farm");
		Book book2 = new Book("Lord of the Files");
		Book book3 = new Book("The Catcher in the Rye");
		
		Cache cache = new Cache();
		cache.addBook(book1);
		cache.addBook(book2);
		cache.addBook(book3);
		
		BookSearch bookSearch = new BookSearch(cache);
		
		if(bookSearch.getBook("Animal Farm") != null)
			System.out.println(bookSearch.getBook("Animal Farm").getTitle() + " está no cache");
		if(bookSearch.getBook("Lord of the Files") != null)
			System.out.println(bookSearch.getBook("Lord of the Files").getTitle() + " está no cache");
		if(bookSearch.getBook("Fahrenheit 451") != null)
			System.out.println(bookSearch.getBook("Fahrenheit 451") + " está no cache");
	}
}
