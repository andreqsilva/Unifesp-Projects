package books;

public class BookSearch implements Library {
	private Cache cache;
	public BookSearch(Cache cache) {
		this.cache = cache;
	}
	
	@Override
	public Book getBook(String title) {
		if(cache.searchBook(title)) {
			return cache.getBook(title);
		}
		return null;
	}
}
