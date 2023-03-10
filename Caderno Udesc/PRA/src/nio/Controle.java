/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package nio;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import verificacao.CheckSumVerification;
import verificacao.DigestVerification;

/**
 *
 * @author nilton
 */

public class Controle {
    private static String DADOS = "src/nio/Dados.txt";
    private static String SEPARATOR = ";";
    CheckSumVerification cksv;
    DigestVerification dv;
    
    private static  HashMap<String,BigInteger> bis;
    
    public Controle() throws IOException{
        bis = new HashMap<>();
        cksv = new CheckSumVerification();
        dv = new DigestVerification();
    }
    
    public HashMap<String, BigInteger> ler() throws Exception{
        try {
            read();
        } catch (Exception ex) {
            Logger.getLogger(Controle.class.getName()).log(Level.SEVERE, null, ex);
        }
                
        List<String> listaPadronizada = conversor(bis);
                
        cksv.verificarCheckSum(cksv.calcularCheckSum(listaPadronizada));
        dv.verificarDigest(dv.calcularDigest(listaPadronizada));
        
        return bis;
    }
    
    private void read() throws IOException{
        
        List<String> list = Files.readAllLines(Paths.get(DADOS));
        ////////////////////////////////////////////////////////
        //////////////////////////teste checkSum ///////////////
        //cksv.verificarCheckSum(cksv.calcularCheckSum(list));//
        //////////////////////////teste msgDigest///////////////
        //dv.verificarDigest(dv.calcularDigest(list));//////////
        ////////////////////////////////////////////////////////
        
        for(String s : list){
            bis.put(s.split(SEPARATOR)[0].trim(), new BigInteger(s.split(SEPARATOR)[1].trim()));
        }
    }
    
    public static List<String> conversor(HashMap<String, BigInteger> dados){
        List<String> list = new ArrayList<>();
        
        for(int i =1; i< bis.size(); i++){
            list.add(i+";"+bis.get(String.valueOf(i)));
        }
        
        return list;
    }
    
    public static void addLine(String valor, BigInteger resultado) throws Exception{
        String linha = valor+";"+resultado;
        
        if(!bis.isEmpty())
            linha="\n"+linha;
        
        bis.put(valor, resultado);
        Files.write(Paths.get(DADOS), linha.getBytes(), StandardOpenOption.APPEND);
        
   
    }
    
    public void finalizar() throws Exception{
        List<String> list = conversor(bis);
        System.out.println("novo ckSum "+cksv.calcularCheckSum(list));
        System.out.println("novo dv "+dv.calcularDigest(list));
        
        cksv.gravar(cksv.calcularCheckSum(list));
        dv.gravar(dv.calcularDigest(list));
    }
}
