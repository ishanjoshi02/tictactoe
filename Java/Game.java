import sun.rmi.runtime.Log;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Game implements ActionListener {
    JFrame mFrame;
    JPanel mPanel;
    JButton[] mButtons;
    String[][] array;
    Player player1, player2;
    Player currentPlayer;
    Game() {
        //Initialising UI Components
        mFrame = new JFrame("Tic Tac Toe");
        mPanel = new JPanel(new GridLayout(3,3));
        mButtons = new JButton[9];
        for (int i = 0;i < 9;i++) {
            mButtons[i] = new JButton("");
            mButtons[i].setBackground(Color.WHITE);
            mButtons[i].addActionListener(this);
            mButtons[i].setFont(new Font("Roboto", 72, 72));
            mPanel.add(mButtons[i]);
        }

        array = new String[3][3];
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                array[i][j] = "";

        //Initialising Players here
        player1 = new Player("Player 1", "X", Color.RED);
        player2 = new Player("Player 2", "O", Color.CYAN);
        currentPlayer = player1;

        mFrame.add(mPanel);
        mFrame.setSize(new Dimension(400, 400));
        mFrame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton currentButton = (JButton) e.getSource();
        if (currentButton.getText().equals("")) {

            int index = getButtonIndex(currentButton);
            String currentSymbol = currentPlayer.getSymbol();

            currentButton.setBackground(currentPlayer.getColor());
            currentButton.setText(currentSymbol);

            array[index / 3][index % 3] = currentSymbol;

            Logic();
            swapPlayers();
        }
    }

    void swapPlayers() {
        if (currentPlayer == player1)
            currentPlayer = player2;
        else
            currentPlayer = player1;
    }

    void Logic() {
        //Traversing Across

        int count;
        String symbol;
        for (int i = 0;i < 3;i++) {
            count = 0;
            symbol = array[i][0];
            for (int j = 1;j < 3;j++) {
                if (array[i][j] == symbol)
                    count++;
            }
            if (count == 2 && !symbol.equals("")){
                exitProtocol();
            }
        }

        //Traversing Down

        for (int i = 0;i < 3;i++) {
            count = 0;
            symbol = array[0][i];
            for (int j = 1;j < 3;j++) {
                if (array[j][i] == symbol)
                    count++;
            }
            if (count == 2 && !symbol.equals("")){
                exitProtocol();
            }
        }

        //Traversing Diagonally
        if (array[0][0]==array[1][1] && array[0][0]==array[2][2] && array[0][0]!="")
            exitProtocol();
        if (array[0][2]==array[1][1] && array[1][1]==array[2][0] && array[0][2]!="")
            exitProtocol();
    }

    int getButtonIndex(JButton currentButton) {
        for (int i = 0;i < 9;i++)
            if (currentButton.equals(mButtons[i]))
                return i;
        return -1;
    }

    void exitProtocol() {
        //todo Rewrite Exit Protocol
        JPanel panel = new JPanel();
        JTextArea textArea = new JTextArea(currentPlayer.getName() + " Wins");
        textArea.setSize(new Dimension(400, 400));
        textArea.setBackground(Color.WHITE);
        mFrame.remove(mPanel);
        panel.setLayout(new FlowLayout());
        panel.add(textArea);
        mFrame.add(panel);
    }
}
