package UVA;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class PowerOfCryptography113 {

	private static BigInteger pow(BigInteger b, int p){
		if(p == 1) return b;
		if(p == 2) return b.multiply(b);
		if(p%2 == 0){
			BigInteger h = pow(b,p/2);
			return h.multiply(h);
		}
		else{
			BigInteger h = pow(b,p/2);
			return h.multiply(h).multiply(b);
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while((line = br.readLine()) != null && !line.isEmpty()){
			int n = Integer.parseInt(line);
			BigInteger p = new BigInteger(line = br.readLine());
			if(n==1) System.out.println(p);
			else{
				int l = p.toString().length();
				int powr = l/n+1;
				int powl = (l-1)/n;
				String s = "1";
				for(int i = 0; i < powl; i ++){
					s+="0";
				}
				BigInteger left = new BigInteger(s);
				for(int i = powl; i <= powr; i ++){
					s+="0";
				}
				BigInteger two = new BigInteger("2");
				BigInteger right = new BigInteger(s);
				while(left.compareTo(right) <= 0){
					BigInteger prom = right.subtract(left).divide(two);
					//System.out.println(left+" "+right);
					
					prom = prom.add(left);	
					//System.out.println("Binsearch at "+prom);
					BigInteger pow = pow(prom,n);
					if(pow.equals(p)) {
						System.out.println(prom);
						break;
					}
					else if(pow.compareTo(p) < 0){
						left = prom.add(BigInteger.ONE);
					}
					else{
						right = prom.subtract(BigInteger.ONE);
					}
				}
			}
		}
		

	}
}
