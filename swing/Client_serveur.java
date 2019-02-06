import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;
import java.awt.Dimension;



public class Client_serveur extends JFrame
{
	
	
	private static JTextField textField;
	
	

	private static final long serialVersionUID = 2L;

	private Client client;

	private static JTextArea textArea;

	public Client_serveur(Client cl) {this.client = cl;}

	public void afficher() {
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		textArea = new JTextArea(25, 25);
		textField = new JTextField("");
		textField.setColumns(25);

		JScrollPane scrollPane = new JScrollPane(textArea);
		JPanel panel = new JPanel();
		JToolBar bar = new JToolBar();
		


		ListAction listAction = new ListAction("Tout lister");
		
		PlayAction playAction = new PlayAction("Jouer");
		CloseAction closeAction = new CloseAction("Fermer");
		

		JButton closeButton = new JButton(closeAction);

		JButton listButton = new JButton(listAction);
		JButton playButton = new JButton(playAction);

		JMenuBar menuBar = new JMenuBar();
		JMenu menu = new JMenu("Le menu");
		
		
		menu.add(new JMenuItem(playAction));
		
		menu.add(new JMenuItem(listAction));
		menu.add(new JMenuItem(closeAction));

		menuBar.add(menu);

		setJMenuBar(menuBar);

		

		closeButton.setPreferredSize(new Dimension(60, 25));
		listButton.setPreferredSize(new Dimension(60, 25));
		playButton.setPreferredSize(new Dimension(60, 25));

		
		
		bar.add(textField);
		bar.add(listButton);
		bar.add(closeButton);
		bar.add(playButton);

		
		add(scrollPane, BorderLayout.SOUTH);

		add(bar, BorderLayout.NORTH);

		pack();
		setVisible(true);
	}

	String parser_resultat(String result) {return result.replace("||", "\n");}


		class PlayAction extends AbstractAction {
		private static final long serialVersionUID = 311826484193L;
		public PlayAction(String nom) {super(nom);}
		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("Jouer " + textField.getText());
			textArea.append(parser_resultat(response));
		}
	}




		class ListAction extends AbstractAction {
		private static final long serialVersionUID = 311826484192L;
		public ListAction(String nom) {super(nom);}
		@Override
		public void actionPerformed(ActionEvent e) {
			String response = client.send("LIST");
			textArea.append(parser_resultat(response));
		}
	}

		class CloseAction extends AbstractAction {
		private static final long serialVersionUID = 311826484191L;
		public CloseAction(String nom) {super(nom);}
		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);

		}
	}




}