import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
public class Hash {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        MessageDigest md5 = MessageDigest.getInstance("MD5"); //Init
        String toHash = "was geht ab";
        md5.update(toHash.getBytes()); //MessageDigest erwartet ein Byte-Array
        byte[] hash = md5.digest(); //MessageDigest gibt ein Byte-Array zurück
        String hexValue = byteArrayToHex(hash); //Bytearray in Hexadezimalwert
        System.out.println(hexValue); //Ausgabe als Hexadezimalwert
        System.out.println("Hi braa");
    }
/**
 * Wandelt die Eingabe in einen Hexadezimalwert um
 * @param a das Byte-Array, dass zu einem Hexadezimalwert gewandelt werden soll
 * @return Hexadezimalrepraesentation von a
 */
public static String byteArrayToHex(byte[] a) {
    StringBuilder sb = new StringBuilder(a.length * 2);
    for(byte b: a)
        sb.append(String.format("%02x", b));
    return sb.toString().toUpperCase();
}
}
