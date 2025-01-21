package algoritmo_rsa;

import java.math.BigInteger;
import java.security.SecureRandom;

public class GestoreRSA {
    private static final int LUNGHEZZA_CHIAVE = 16; // Ridotto per scopi didattici
    private ChiaveRSA chiavePubblica;
    private ChiaveRSA chiavePrivata;
    
    public void generaChiavi() {
        System.out.println("\n=== PROCESSO DI GENERAZIONE DELLE CHIAVI ===");
        SecureRandom random = new SecureRandom();
        
        // 1. Genera due numeri primi p e q
        System.out.println("\nPasso 1: Generazione numeri primi");
        System.out.println("----------------------------------");
        BigInteger p = BigInteger.probablePrime(LUNGHEZZA_CHIAVE, random);
        BigInteger q = BigInteger.probablePrime(LUNGHEZZA_CHIAVE, random);
        System.out.println("p = " + p);
        System.out.println("q = " + q);
        
        // 2. Calcola n = p * q
        System.out.println("\nPasso 2: Calcolo del modulo n");
        System.out.println("-----------------------------");
        BigInteger n = p.multiply(q);
        System.out.println("n = p * q = " + n);
        
        // 3. Calcola φ(n) = (p-1)(q-1)
        System.out.println("\nPasso 3: Calcolo di φ(n)");
        System.out.println("-------------------------");
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        System.out.println("φ(n) = (p-1)(q-1) = " + phi);
        
        // 4. Scegli e (esponente pubblico)
        System.out.println("\nPasso 4: Scelta dell'esponente pubblico e");
        System.out.println("---------------------------------------");
        BigInteger e = BigInteger.valueOf(65537);
        System.out.println("e = " + e);
        
        // 5. Calcola d (esponente privato)
        System.out.println("\nPasso 5: Calcolo dell'esponente privato d");
        System.out.println("----------------------------------------");
        BigInteger d = e.modInverse(phi);
        System.out.println("d = " + d);
        
        chiavePubblica = new ChiaveRSA(e, n);
        chiavePrivata = new ChiaveRSA(d, n);
        
        System.out.println("\n=== RIEPILOGO CHIAVI ===");
        System.out.println("Chiave Pubblica (e,n):");
        System.out.println("e = " + chiavePubblica.getEsponente());
        System.out.println("n = " + chiavePubblica.getModulo());
        System.out.println("\nChiave Privata (d,n):");
        System.out.println("d = " + chiavePrivata.getEsponente());
        System.out.println("n = " + chiavePrivata.getModulo());
    }
    
    public BigInteger crittografa(String messaggio) {
        byte[] messaggioBytes = messaggio.getBytes();
        BigInteger m = new BigInteger(1, messaggioBytes);
        
        System.out.println("\n=== PROCESSO DI CRITTOGRAFIA ===");
        System.out.println("Messaggio originale: " + messaggio);
        System.out.println("Messaggio convertito in numero: " + m);
        System.out.println("\nFormula: C = M^e mod n");
        System.out.println("Dove:");
        System.out.println("M = " + m);
        System.out.println("e = " + chiavePubblica.getEsponente());
        System.out.println("n = " + chiavePubblica.getModulo());
        
        BigInteger crittografato = m.modPow(chiavePubblica.getEsponente(), chiavePubblica.getModulo());
        System.out.println("\nRisultato della crittografia: " + crittografato);
        return crittografato;
    }
    
    public String decrittografa(BigInteger messaggioCrittografato) {
        System.out.println("\n=== PROCESSO DI DECRITTOGRAFIA ===");
        System.out.println("Messaggio crittografato: " + messaggioCrittografato);
        System.out.println("\nFormula: M = C^d mod n");
        System.out.println("Dove:");
        System.out.println("C = " + messaggioCrittografato);
        System.out.println("d = " + chiavePrivata.getEsponente());
        System.out.println("n = " + chiavePrivata.getModulo());
        
        BigInteger m = messaggioCrittografato.modPow(chiavePrivata.getEsponente(), chiavePrivata.getModulo());
        String messaggioDecrittografato = new String(m.toByteArray());
        System.out.println("\nMessaggio decrittografato: " + messaggioDecrittografato);
        return messaggioDecrittografato;
    }
    
    public ChiaveRSA getChiavePubblica() {
        return chiavePubblica;
    }
    
    public ChiaveRSA getChiavePrivata() {
        return chiavePrivata;
    }
} 