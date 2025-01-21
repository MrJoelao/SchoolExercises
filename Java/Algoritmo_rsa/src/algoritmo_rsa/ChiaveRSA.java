package algoritmo_rsa;

import java.math.BigInteger;

public class ChiaveRSA {
    private BigInteger esponente;
    private BigInteger modulo;
    
    public ChiaveRSA(BigInteger esponente, BigInteger modulo) {
        this.esponente = esponente;
        this.modulo = modulo;
    }
    
    public BigInteger getEsponente() {
        return esponente;
    }
    
    public BigInteger getModulo() {
        return modulo;
    }
} 