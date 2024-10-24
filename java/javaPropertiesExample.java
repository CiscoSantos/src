import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class AppConfig {
    public static void main(String[] args) {
        Properties properties = new Properties();
        
        try (FileInputStream input = new FileInputStream("src/main/resources/config.properties")) {
            properties.load(input);

            // Access properties
            String dbUrl = properties.getProperty("db.url");
            String apiKey = properties.getProperty("api.key");
            String logLevel = properties.getProperty("log.level");

            System.out.println("Database URL: " + dbUrl);
            System.out.println("API Key: " + apiKey);
            System.out.println("Log Level: " + logLevel);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}

