import java.util.*;

class PassByReference{

    static LinkedList<Integer> L = new LinkedList<Integer>(Arrays.asList(1,2,3,4,5));
    
    static int a = 10;
    static int i0 = 1;
    static int j0 = 5;

    public static void print(Object o){
        System.out.println(o);
    }

    public static void PBR(LinkedList<Integer> L){
        L.removeLast();
        return;
    }

    public static void PBR2(int b){
        a -= b;
    }

    public static void swap(int i0, int j0){
        int temp = i0;
        i0 = j0;
        j0 = temp;
        
        return;
    }

    public static void main(String[] args) {
        // PassByReference P = new PassByReference();
        // print(P.L);
        // PassByReference.PBR(P.L);
        // print(P.L);

        // print("before PBR2: ");
        // print(PassByReference.a);
        // PassByReference.PBR2(3);
        // print("after PBR2: ");
        // print(PassByReference.a);
        print(L);
        PBR(L);
        print(L);



        // int i = 1; int j = 5;
        // PassByReference.swap(i, j);
        // print(i); print(j);
        // print("=============");
        // print('\n');

        // PassByReference.swap(PassByReference.i0, PassByReference.j0);
        // print(PassByReference.i0); print(PassByReference.j0);
    }



}