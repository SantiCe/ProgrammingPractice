package UVA;
/**
 * MORALEJA: Sort Arrays ES MEJOR que TreeSet. 
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;


public class HardwoodSpecies10226 {

	public static final void main(String args[])throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		br.readLine();
		int count = 0;
		while(count < n){
			int treecount = 0;
			if(count != 0) System.out.println();
			HashMap<String, Integer> map = new HashMap<String,Integer>();
			String line = br.readLine();
			//TreeSet<String> set = new TreeSet<String>();
			while(line != null && !line.isEmpty()){
				if(map.containsKey(line)){
					int i = map.remove(line);
					++i;
					map.put(line, i);
				}
				else{
					map.put(line, 1);
				}
				//set.add(line);
				treecount++;
				line = br.readLine();
			}
			String[] set = new String[map.size()];
			map.keySet().toArray(set);
			Arrays.sort(set);
			DecimalFormat f = new DecimalFormat("0.0000");
			for(String s:set){
				System.out.println(s+" "+f.format(100*((double)map.get(s)/(double)treecount)).replace(",", "."));
			}
			
			count++;
		}
	}
	
	

}
