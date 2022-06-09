package adapter;
import java.util.Enumeration;
import java.util.Iterator;

public class AdapterEnumeration implements Enumeration{
	private Iterator iterator;
	
	public AdapterEnumeration(Iterator iterator) {
		this.iterator = iterator;
	}
	
	@Override
	public boolean hasMoreElements() {
		if(iterator.hasNext())
			return true;
		return false;
	}

	@Override
	public Object nextElement() {
		return iterator.next();
	}	
}
