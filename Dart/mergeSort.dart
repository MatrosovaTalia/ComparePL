import "dart:io";

void main() {
  File myFile = new File("array.txt");
  String myFileContent = myFile.readAsStringSync();
  List<String> mylist = myFileContent.split(' ');
  var arr = [];
  var L = mylist.length;
  for (var i = 0; i < L; i++) arr.add(int.parse(mylist[i]));

  Stopwatch stopwatch = new Stopwatch()..start();
  arr = merge(arr);
  print(stopwatch.elapsedMicroseconds.toDouble() / 1000); // executing time in microseconds
}

List merge(arr){
  if(arr.length > 1){
    var L = arr.length;
    var a1 = arr.sublist(0, L ~/ 2);
    var a2 = arr.sublist(L ~/ 2, L);
    a1 = merge(a1);
    a2 = merge(a2);
    var i = 0;
    var j = 0;
    var k = 0;
    while(i < a1.length && j < a2.length){
      if(a1[i] < a2[j]){
        arr[k] = a1[i];
        i++;
      }
      else{
        arr[k] = a2[j];
        j++;
      }
      k++;
    }
    while(i < a1.length){
      arr[k] = a1[i];
      i++;
      k++;
    }
    while(j < a2.length){
      arr[k] = a2[j];
      j++;
      k++;
    }
  }
  return arr;
}
