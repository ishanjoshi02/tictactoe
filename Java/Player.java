import java.awt.Color;

public class Player {
    private String name, symbol;
    private Color color;
    Player(String name, String symbol, Color color) {
        this.name = name;
        this.symbol = symbol;
        this.color = color;
    }

    public Color getColor() {
        return color;
    }

    public String getName() {
        return name;
    }

    public String getSymbol() {
        return symbol;
    }
}
