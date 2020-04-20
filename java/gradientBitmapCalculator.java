class gradientBitmapCalculator{

    public static void fillGradientLine(int[] arr, int line, int w, int a, int b){
        int delta = b - a;
        int offset = line * w;
        for (int i = 0; i < w; i++){
            float fraction = (float) i / (float) w;
            arr[offset + i] = a + (int) ((float) delta * fraction);
        }
    }
    
    public static int[] generateGrayGradient(int h, int w, int a, int b){
        int size = w * h;
        int[] arr = new int[size];
        for (int i = 0; i < h; i++){
            fillGradientLine(arr, i, w, a, b);
        }
        return arr;
    }
    public static void saveGradient(int[] arr, int h, int w, int b){
        System.out.printf(java.lang.String.format("P2\n%d %d\n%d\n", w, h, b));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                System.out.print(arr[i * w + j]);
                System.out.print(" ");
            }
            System.out.println("");
        }
    }
    
    public static void main(String[] args) {
        int h = 1000;
        int w = 1000;
        int a = 55;
        int b = 233;

        final double startTime = System.nanoTime() / 1000000.0;
        generateGrayGradient(h, w, a, b);
        final double endTime = System.nanoTime() / 1000000.0;
        System.out.println(endTime - startTime);

        // saveGradient(arr, h, w, b);

        
    }
}
