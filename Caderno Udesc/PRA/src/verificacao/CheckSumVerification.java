/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package verificacao;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author nilton
 */
public class CheckSumVerification {
    private static String CHECKSUM = "src/nio/CheckSum.txt";
    private List<String> ck = new ArrayList<>();
    private String salvo;
        
    public CheckSumVerification() throws IOException{
        ck = Files.readAllLines(Paths.get(CHECKSUM));
        
        if(ck.size()>1)
            throw new IOException("Erro! Muitos valores em checksum.txt!! Verifique!");
        salvo = ck.get(0).trim();
        
    }    
    
    public void verificarCheckSum(String cksum) throws Exception{
        System.out.println("CheckSumVerification");
        System.out.println("calculado " + cksum);
        System.out.println("arquivo   "+ salvo);
        
        if(cksum.compareTo(salvo)!=0){
            throw new Exception("Erro! Arquivo alterado!");
        }
    }
    
    public String calcularCheckSum(List<String> list) throws IOException, Exception{
        byte bytes[] = new byte[list.size()];
        byte sum = 0;
        
        for(String s : list){
            sum+=checksum(s.getBytes());
        }
        
        return String.valueOf(sum);
    }
    
    private byte checksum(byte[] input) {
        byte checksum = 0;
        for (byte cur_byte: input) {
            checksum = (byte) (((checksum & 0xFF) >>> 1) + 
                    ((checksum & 0x1) << 7)); // Rotate the accumulator
          checksum = (byte) ((checksum + cur_byte) & 0xFF);                          
       // Add the next chunk
        }
        return checksum;
    }
    
    public void gravar(String sum) throws IOException{
        sum = sum.trim();
         Files.write(Paths.get(CHECKSUM), sum.getBytes());
    }
}
