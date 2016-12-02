import java.math.BigInteger;
import java.util.Scanner;

public class    Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int i=1;i<=t;i++)
        {
            if(i!=1)
                System.out.println("");
            BigInteger x = in.nextBigInteger();
            BigInteger y=in.nextBigInteger();
            System.out.println("Case "+i+":");
            System.out.println(x+" + "+y+" = "+ x.add(y));
        }
    }
}

