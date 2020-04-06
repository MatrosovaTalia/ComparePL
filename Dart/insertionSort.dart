import "dart:io";

void main() {
  File myFile = new File("array.txt");
  String myFileContent = myFile.readAsStringSync();
  List<String> mylist = myFileContent.split(' ');
  var arr = [];
  var L = mylist.length;
  for (var i = 0; i < L; i++) arr.add(int.parse(mylist[i]));

  Stopwatch stopwatch = new Stopwatch()..start();
  for (var i = 1; i < L; i++) {
    var j = i;
    var buf = arr[i];
    while (j > 0 && arr[j - 1] > buf) {
      arr[j] = arr[j - 1];
      j -= 1;
    }
    arr[j] = buf;
  }
  print(stopwatch.elapsedMicroseconds.toDouble() / 1000); // executing time in microseconds
}
