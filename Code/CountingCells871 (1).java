package UVA;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class CountingCells871 {
	
	private static int m,n,len;
	static int dx[] = {-1,0,1,1,1,0,-1,-1};
	static int dy[] = {1,1,1,0,-1,-1,-1,0};
	private static boolean marc[][] = new boolean[26][26];
	private static boolean mat[][] = new boolean[26][26];
	
	static boolean inBound(int x, int y){
	    return (x >= 0 && x < m && y>= 0 && y < n);
	}
	
	static void dfs(int x, int y){
	    if(marc[x][y]) return;
	    ++len;
	    marc[x][y] = true;
	    for(int i = 0; i < 8; i ++){
	        int nx = x+dx[i];
	        int ny = y+dy[i];
	        if(!inBound(nx,ny)) continue;
	        if(mat[nx][ny] && !marc[nx][ny]) dfs(nx,ny);
	    }
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		br.readLine();
		while(--T >= 0){
			for(int i = 0; i < 26; i ++){
				for(int j = 0; j < 26; j ++){
					marc[i][j] = false;
					mat[i][j] = false;
				}
			}
			
			String line = br.readLine();
			n = line.length();
			m = 0;
			while(line != null && !line.isEmpty()){
				for(int i = 0; i < n; i ++){
					mat[m][i] = line.charAt(i) == '1';
				}
				++m;
				line = br.readLine();
			}
			
			int mlen = 0;
	        len = 0;
	        for(int i = 0; i < m; i++){
	            for(int j = 0; j < n; j ++){
	                if(!marc[i][j] && mat[i][j]){
	                        dfs(i,j);
	                        mlen = Math.max(len,mlen);
	                        len = 0;
	                }
	            }
	        }
	        
	        System.out.println(mlen);
	        if(T != 0) System.out.println();
	        
		}
		
	}
	
}
