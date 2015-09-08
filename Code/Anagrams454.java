package UVA;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;

public class Anagrams454 {

	public static class E{
		public Character[] c;

		public E(String s){
			ArrayList<Character> list = new ArrayList<Character>();
			for(int i = 0; i < s.length(); i ++){
				if(s.charAt(i) != ' '){
					list.add(s.charAt(i));
				}
			}
			c = new Character[list.size()];
			list.toArray(c);
			Arrays.sort(c);
		}

		public int hashCode(){
			return c.length + (c[0]-26);
		}

		public boolean equals(Object ee){
			E e = (E)ee;
			if(e.c.length != c.length) return false;
			for(int i = 0; i < c.length; i ++){
				if(c[i] != e.c[i]) return false;
			}
			return true;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String line = br.readLine();

		
		while(--N >=0){
			HashMap<E, LinkedList<String>> map = new HashMap<E,LinkedList<String>>();
			ArrayList<String> list = new ArrayList<String>();
			while((line = br.readLine()) != null && !line.isEmpty()){
				E e = new E(line);
				if(!map.containsKey(e)){
					map.put(e, new LinkedList<String>());
				}
				map.get(e).add(line);
				list.add(line);
//				String s = "";
//				for(int i = 0; i < e.c.length; i ++){
//					s+=e.c[i];
//				}
//				System.out.println(line+" "+s);
			}
			String[] ar = new String[list.size()];
			list.toArray(ar);
			Arrays.sort(ar);
			Collection<E> col = map.keySet();
//			System.out.println(col.size());
			HashMap<E, LinkedList<String>> mapp = new HashMap<E,LinkedList<String>>();
			for(E e:col){
//				String s = "";
//				System.out.println("HEY");
//				for(int i = 0; i < e.c.length; i ++){
//					s+=e.c[i];
//				}
//				System.out.println(s);
				LinkedList<String> array = map.get(e);
				String[] arar = new String[array.size()];
				array.toArray(arar);
				Arrays.sort(arar);
				array = new LinkedList<String>();
				for(int i = 0; i < arar.length; i ++){
					array.add(arar[i]);
				}
				mapp.put(e,array);
			}
			map = mapp;
			for(int i = 0; i < list.size(); i ++){
				String s = ar[i];
				E e = new E(s);
				LinkedList<String> entries = map.get(e);
				boolean first = true;
				for(String st:entries){
					if(first){
						first = false;
						continue;
					}	
					System.out.println(s+" = "+st);
				}
				map.get(e).pop();
			}
			if(N != 0)System.out.println();
			
		}

	}



}
