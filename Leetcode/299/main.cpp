ass Solution {
	public:
    string getHint(string secret, string guess) {
	        int bull    = 0;
	        int cow     = 0;
	        
	        int sArr[10]= {0};
	        int gArr[10]= {0};
	        
	        for (int i = 0; i < secret.size(); i++){
			            if (secret[i] == guess[i]){
						                bull++;
						            }else{
									                sArr[secret[i]  - '0']++;
									                gArr[guess[i]   - '0']++;
									            }
			        }
	        
	        for (int i = 0; i < 10; i ++){
			            cow += min(sArr[i], gArr[i]);
			        }
	        
	        return to_string(bull) + 'A' + to_string(cow) + 'B';
	        
	    }
};
