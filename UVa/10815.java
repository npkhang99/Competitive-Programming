import java.util.*;

class Main{
    private static String st;
    private static Scanner sc = new Scanner(System.in);
    private static TreeSet<String> dict = new TreeSet<String>();

    private static String add(String st){
        StringBuilder newString = new StringBuilder();
        for(int i=0; i<st.length(); i++){
            if(Character.isAlphabetic(st.charAt(i))){
                newString.append(Character.toLowerCase(st.charAt(i)));
                continue;
            }
            if(newString.length() > 0)
                dict.add(newString.toString());
            newString = new StringBuilder();
        }
        if(newString.length() > 0)
            dict.add(newString.toString());
        return newString.toString();
    }

    public static void main(String[] args){
        dict.clear();
        while(sc.hasNext()){
            st = sc.next();
            st = add(st);
        }
        for(String word:dict)
            System.out.println(word);
    }
}
