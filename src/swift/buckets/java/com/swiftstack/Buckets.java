import java.util.*;

abstract class Callable {
  public abstract Integer call(List group);
}

class NumericalSum extends Callable {
  public NumericalSum() {}
  public Integer call(List group) {
    Integer total = 0;
    for (int i=0; i< group.size(); ++i) {
      Integer element = (Integer) group.get(i);
      total += element.intValue();
    }
    return total;
  }
}

class HistogramReport {
  public Callable operation;
  public HistogramReport(Callable operation) {
    this.operation = operation;
  }

  public List groupAndProcessByLastDigit(List numbers) {
    List array = new ArrayList<Integer>();

    List array1 = new ArrayList<Integer>();
    for (Object number : numbers) {
      int i = (Integer) number;
      if (i < 100) {
	array1.add(i);
      }
    }

    List<Integer>[] digit_groups = new ArrayList[10];

    for (int i=0; i < 10; ++i) {
      digit_groups[i] = new ArrayList<Integer>();
    }

    for (Object element : array1) {
      int i = (Integer) element;
      String last = ("" + i).substring(("" + i).length() - 1);
      digit_groups[Integer.valueOf(last)].add(i);
    }

    for (int i=0; i<10; ++i) {
      Integer result = this.operation.call(digit_groups[i]);
      array.add(result);
    }

    List array2 = new ArrayList<Integer>();
    for (Object number : numbers) {
      int i = ((Integer) number).intValue();
      if (i >= 100) {
	array2.add(i);
      }
    }

    if (array2.size() > 0) {
      Integer result = this.operation.call(array2);
      array.add(result);
    }

    return array;
  }
}

public class Buckets {
  public static void main(String[] argv) {
    List<Integer> numbers = new ArrayList<Integer>();

    Scanner sc = new Scanner(System.in);
    while(sc.hasNextLine()) {
      for (String s : sc.nextLine().split(" +")) {
	numbers.add(Integer.valueOf(s));
      }
    }
    List report = new HistogramReport(new NumericalSum()).
      groupAndProcessByLastDigit(numbers);
    for (Object element : report) {
      Integer intElement = (Integer) element;
      System.out.println(element);
    }
  }
}

