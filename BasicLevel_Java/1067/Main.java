import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String ans = in.next(); String s = null;
    int N = in.nextInt();
    int cnt = 0;
    in.nextLine();  // 读取一个空串
    for (;;) {
      s = in.nextLine();
      if (s.equals("#")) break;
      cnt++;
      if (s.equals(ans) && cnt <= N) {
        System.out.println("Welcome in"); break;
      } else if (!s.equals(ans) && cnt <= N) {
        System.out.println("Wrong password: " + s);
        if (cnt == N) {
          System.out.println("Account locked");
          break;
        }
      }
    }
    in.close();
  }    
}
