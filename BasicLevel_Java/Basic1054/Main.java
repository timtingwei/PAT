import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < T; i++) {
      double x = 0;
      String s = null;
      try {
        s = in.next();
        x = Double.parseDouble(s);
        double temp = Double.parseDouble(String.format("%.2f", x));
        if (x < -1000 || x > 1000 || Math.abs(temp - x) >= 0.001) {
          throw new NumberFormatException();    // 要加括号
        }

        sum += x;
        cnt++;
      } catch (NumberFormatException e) {
        System.out.println("ERROR: " + s + " is not a legal number");
      }
    }
    in.close();

    if (cnt == 0) {
      System.out.println("The average of 0 numbers is Undefined");
    } else if (cnt == 1) {
      System.out.printf("The average of 1 number is %.2f\n", sum);
    } else {
      System.out.printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }
  }
}

/*
输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

输入样例2：

2
aaa -9999

输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
