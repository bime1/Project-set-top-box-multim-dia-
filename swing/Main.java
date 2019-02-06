
public class Main
{

	
	static final int DEFAULT_PORT = 3331;
	
	static final int WIDTH = 700;
	static final int HEIGHT = 320;
	
	static final String DEFAULT_HOST = "localhost";

	public static void main(String argv[])
	{
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		if (argv.length >= 1) host = argv[0];
		if (argv.length >= 2) port = Integer.parseInt(argv[1]);

		Client client = null;
		Client_serveur Client_serveur = null;
		try {
			client = new Client(host, port);
			Client_serveur = new Client_serveur(client);
			Client_serveur.afficher();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}