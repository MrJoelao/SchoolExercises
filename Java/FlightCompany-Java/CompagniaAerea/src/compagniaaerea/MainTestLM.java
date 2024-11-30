package compagniaaerea;

/**
 *
 * @author joels
 */
public class MainTestLM {
    public static void main(String[] args) {
        // Creazione di un'istanza di LoginManager
        LoginManager loginManager = new LoginManager("credentials.dat", "admin", "admin", true);

        // Caricamento delle credenziali
        loginManager.loadCredentials();

        // Aggiunta di nuove credenziali
        loginManager.addCredentials("Luca", "P@ssw0rd123", false);
        loginManager.addCredentials("Joel", "Password1@", true);
        loginManager.addCredentials("LucaAdmin", "P@ssw0rd422", true);
        loginManager.addCredentials("Pietro", "SecretPass2!", false);
        loginManager.addCredentials("Laura", "StrongPwd10#", false);
        loginManager.addCredentials("Jacopo", "SecurePass10@", false);
        loginManager.addCredentials("Giulia", "SafePassword10$", false);
        loginManager.addCredentials("Marco", "ProtectedPass10%", false);
        loginManager.addCredentials("Elena", "ConfidentialPwd10^", false);
        loginManager.addCredentials("Andrea", "HiddenPass10&", false);
        loginManager.addCredentials("ValentinaAdmin", "T0pS3cretPwd10*", true);
        loginManager.addCredentials("Valentina", "TopSecretPwd10*", false);
        loginManager.addCredentials("Davide", "ClassifiedPass10#", false);
        loginManager.addCredentials("Sara", "EncryptedPwd10@", false);
        loginManager.addCredentials("Matteo", "AccessGranted10^", false);



        // Stampa dell'elenco delle credenziali
        loginManager.printCredentialsList();

        // Salvataggio delle credenziali
        loginManager.saveCredentials();
    }
}