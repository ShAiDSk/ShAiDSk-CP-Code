import java.util.Scanner;
import java.math.BigInteger;

class main{
    public static void main(String[] args){
        BigInteger fac = BigInteger.ONE;
        for (int i = 2; i <= 25; i++){
            fac = fac.multiply(BigInteger.valueOf(i));
        }
        System.out.println(fac); // 15511210043330985984000000
        // System.out.println("Hello");
    }
}