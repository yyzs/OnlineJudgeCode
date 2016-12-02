import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
            BigDecimal x = in.nextBigDecimal();
            BigDecimal y = in.nextBigDecimal();
            System.out.println(x.add(y).stripTrailingZeros().toPlainString());
        }
    }
}

