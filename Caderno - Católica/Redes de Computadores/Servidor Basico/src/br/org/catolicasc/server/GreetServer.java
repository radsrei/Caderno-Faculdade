package br.org.catolicasc.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class GreetServer {
    private ServerSocket serverSocket;
    private Socket clienteSocket;
    private PrintWriter out;
    private BufferedReader in;


    public void start(int port) throws IOException {
        //inicializar atributos
        serverSocket = new ServerSocket(port); //escuta na porta port
        clienteSocket = serverSocket.accept(); //espera conexão
        out = new PrintWriter(clienteSocket.getOutputStream(),true); //handler para escrita de dados
        in = new BufferedReader(new InputStreamReader((clienteSocket.getInputStream()))); // handler para leitura de dados

        clienteHandler();
    }


    private void clienteHandler() throws IOException {
        /*String greeting; //fica travado até receber uma mensagem
        do {
            greeting = in.readLine();
            if ("hello server".equals(greeting)) {
                out.println("hello client");
            } else if (!"!quit".equals(greeting)) {
                out.println("Mensagem incorreta");
            }
        } while (!"!quit".equals(greeting));*/

        String greeting = in.readLine();

        while (!"!quit".equals(greeting)){
            if ("hello server".equals(greeting)) {
                out.println("hello client");
            } else {
                out.println("Mensagem incorreta");
            }
            greeting = in.readLine();
        }

        out.println("Desligando servidor.");
    }

    public void stop() {
        try {
            in.close();
            out.close();
            clienteSocket.close();
            serverSocket.close();
        } catch (IOException ex) {
            System.out.println("Erro ao fechar a conexão.");
        }

    }

    public static void main(String[] args) {
        GreetServer server = new GreetServer();
        try {
            server.start(12345);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            server.stop();
        }
    }
}