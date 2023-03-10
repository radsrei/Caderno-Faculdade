package superfatorial;

import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import nio.Controle;

public class SuperFatorialComCacheDisco extends SuperFatorialComCache {

    /**
     * Antes de calcular o fatorial busca no cache
     *
     * @author udesc
     *
     */
    /**
     * Cache em memória para o super fatorial
     * @param in
     * @param bi
     * @throws java.io.IOException
     */

    @Override
    public void addCache(String in, BigInteger bi) throws IOException {
        if (!getCache().containsKey(in)) {
            getCache().put(in, bi);
            try {
                Controle.addLine(in, bi);
            } catch (Exception ex) {
                Logger.getLogger(SuperFatorialComCacheDisco.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }
    
    public void initCache(HashMap<String, BigInteger> list) {
        this.getCache().putAll(list);
    }
    
}
