## Basic-Java-Solution

### 1054 求平均值（20 point(s)）

本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

#### 输入格式：

输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

#### 输出格式：

对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

#### 输入样例 1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

#### 输出样例 1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

#### 输入样例 2：
2
aaa -9999

#### 输出样例 2：

ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

#### Solution:

用Java抛出异常机制做, try {..} catch {...},try的内部可以修改变量, 可以手动抛出错误

注意case2: number数量为1的时候
```java
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
```

### 1067 试密码（20 point(s)）
当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

#### 输入格式：
输入在第一行给出一个密码（长度不超过 20 的、不包含空格、Tab、回车的非空字符串）和一个正整数 N（≤ 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个 # 字符时，输入结束，并且这一行不是用户的输入。

#### 输出格式：
对用户的每个输入，如果是正确的密码且尝试次数不超过 N，则在一行中输出 Welcome in，并结束程序；如果是错误的，则在一行中按格式输出 Wrong password: 用户输入的错误密码；当错误尝试达到 N 次时，再输出一行 Account locked，并结束程序。

#### 输入样例 1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#

#### 输出样例 1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked

#### 输入样例 2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#

#### 输出样例 2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in

#### Solution:

三个注意点:

注意点1: 用nextLine()时, 之前读过一行, 还会留下一个换行符没读, 因此只会打印出一个空行, 第二行的字符串不会被读取到。

解决方法是, 在这种情况下, 在之前加一个nextLine()

注意点2: 想清楚操作执行的顺序
> * 读取输入
> * 检查输入是不是#
> * 读取次数+1
> * 正确且不超过N, welcome结束
> * 不正确且不超过N, wrong, 如果这是最后一次机会, 不等下次locked结束

注意点3:如果密码错误且到达了错误次数, 是先输出wrong再输入locked
```java
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
```
