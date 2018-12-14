/*
 *  ParseList: Small side project for tokenizing, parsing/totaling the value and 
    formatting subtotal from an arrayList of strings.
 */
package JavaFxPractice;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Donna
 */
public class ParseList {
    public static void main(String []args){
    ArrayList<String> myCart = new ArrayList<String>();
    DecimalFormat df = new DecimalFormat("$#0.00");
    double subtotal = 0.00;
   myCart.add("Title1 $9.99"); 
   myCart.add("Title2 $19.99");
   
   for(int i = 0; i < myCart.size(); i++){
        String temp = myCart.get(i);
        String [] price = temp.split("\\$");
        double thePrice = Double.parseDouble(price[1]);
        subtotal += thePrice;
    }
    System.out.println(df.format(subtotal));
    }
}
