package br.org.catolicasc.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class GreetClient {
    private Socket clienteSocket;
    private PrintWriter out;
    private BufferedReader in;

    public void start(String ip, int port) throws IOException{
            clienteSocket = new Socket(ip, port);
            out = new PrintWriter(clienteSocket.getOutputStream(), true); //handler para escrita de dados
            in =new BufferedReader(new InputStreamReader((clienteSocket.getInputStream()))); // handler para leitura de dados
    }

    public void stop(){
        try {
            in.close();
            out.close();
            clienteSocket.close();
        } catch (IOException ex) {
            System.out.println("erro ao fecha a conexão.");
        }

    }
    public String sendMessage(String msg) throws IOException{
        out.println(msg);
        return in.readLine();
    }

    public static void main(String[] args){
        GreetClient client = new GreetClient();
        try {
            client.start("127.0.0.1",12345);

            Scanner scanner = new Scanner(System.in);
            System.out.print("entre um mensagem:");
            String mensagem = scanner.nextLine();
            String response = client.sendMessage(mensagem);
            System.out.println("Resposta do servidor: " + response);

            /*String response = client.sendMessage("hello server");
            System.out.println("Resposta do servidor: " + response);

            String response = client.sendMessage("Olá");
            System.out.println("Resposta do servidor: " + response);

            String response = client.sendMessage("!quit");
            System.out.println("Resposta do servidor: " + response);*/
        }catch (IOException ex){
            throw new RuntimeException(ex);
        }finally {
            client.stop();
        }
    }

}
