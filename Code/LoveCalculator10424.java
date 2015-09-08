package UVA;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;


public class LoveCalculator10424 {
	
	public static int digSum(int i){
		if(i < 10) return i;
		else return (i%10) + digSum(i/10);
	}
	
	public static int calc(int n){
		int sum = digSum(n);
		while(sum >= 10) sum = digSum(sum);
		return sum;
	}
	
	public static double value(String s){
		char[] ch = s.toCharArray();
		int n = 0;
		for(int i = 0; i < ch.length; i ++){
			char c = ch[i];
			if(Character.isUpperCase(c)){
				n+=(c-'A')+1;
			}
			else if(Character.isLowerCase(c)){
				n+=(c-'a')+1;
			}
		}
		return calc(n);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while((line = br.readLine()) != null){

			double n1 = value(line);
			double n2 = value(br.readLine());
			if(n1 == 0 && n2 == 0) {
				System.out.println();
				continue;
			}
			else{
				double d = Math.min(n1,n2)/Math.max(n1,n2);
				d*=100;
				DecimalFormat df = new DecimalFormat("0.00");
				System.out.println(df.format(d).replace(',', '.')+" %");
			}
		}
	}

}
