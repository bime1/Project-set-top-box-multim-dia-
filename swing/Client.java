
import java.io.*;
import java.net.*;

public class Client
{
	
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	
	private BufferedWriter output;
	private BufferedReader input;
	
	private Socket sock;
	private static final long serialVersionUID = 2L;


		public String send(String request) {

		try {
			request += "\n";  
			output.write(request, 0, request.length());
			output.flush();
		}
		catch (java.io.IOException e) {
			System.err.println("Le client ne peut pas envoyer le message" + e);
			return null;
		}
		
	
		try {
			return input.readLine();
		}
		catch (java.io.IOException e) {
			System.err.println("Le client ne peut recevoir le message " + e);
			return null;
		}
	}

	
	public Client(String host, int port) throws UnknownHostException, IOException {
		try {
			sock = new java.net.Socket(host, port);
		}
		catch (java.net.UnknownHostException e) {
			System.err.println("Le client ne trouve pas le host "+host+":"+port);
			throw e;
		}
		catch (java.io.IOException e) {
			System.err.println("Le client ne peut atteindre le host "+host+":"+port);
			throw e;
		}
		
		try {
			input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
		}
		catch (java.io.IOException e) {
			System.err.println("Le client ne peut pas ouvrir l'output");
			throw e;
		}
	}
	
	

}