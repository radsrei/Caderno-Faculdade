/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package verificacao;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import nio.Controle;

/**
 *
 * @author nilton
 */

public class DigestVerification {
    private static String DIGEST = "src/nio/Digest.txt";
    private static StringBuffer stringBuffer = new StringBuffer();
    private static MessageDigest messageDigest;

    private StringBuffer hash;
    
    public DigestVerification() throws IOException{
       List<String> list = Files.readAllLines(Paths.get(DIGEST));
       
       hash = new StringBuffer(list.get(0).trim());
    }
    
    public void verificarDigest(StringBuffer sb) throws Exception{
        System.out.println("DigestVerification");
        System.out.println("calculado "+sb);
        System.out.println("arquivo   "+hash);
        //if(!sb.equals(hash)){
        if(sb.toString().compareTo(hash.toString())!=0){
            throw new Exception("Erro! Arquivo alterado!");
        }
        
    }
    
    public StringBuffer calcularDigest(List<String> list){
        stringBuffer = new StringBuffer();
        
        for(String s : list){
            digest(s);
        }
        
        return stringBuffer;
        
    }
    
    private static void digest(String data){
        
        try {
            messageDigest = MessageDigest.getInstance("SHA-512");
        } catch (NoSuchAlgorithmException ex) {
            Logger.getLogger(Controle.class.getName()).log(Level.SEVERE, null, ex);
        }
        
            messageDigest.update(data.getBytes());
            byte[] messageDigestSHA = messageDigest.digest();
        
            for (byte bytes : messageDigestSHA) {
                stringBuffer.append(String.format("%02x", bytes & 0xff));       
        }   
    }
    
    public void gravar(StringBuffer ha) throws IOException{
        
        Files.write(Paths.get(DIGEST), String.valueOf(ha).getBytes());
    }
    
}
