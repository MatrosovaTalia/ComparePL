import Foundation

struct TestStruct {
    var a = 0
    var b = 0
}

class Test {
    var a = 0
    var b = 0
}

var st = TestStruct()
var cl = Test()

var startTime = Date().timeIntervalSinceReferenceDate

for i in 1...100000 {
    st.a = i
    st.b = i
}

var timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("Struct access took \(timeElapsed) ms")

//##########

startTime = Date().timeIntervalSinceReferenceDate

for i in 1...100000 {
    cl.a = i
    cl.b = i
}

timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("Class access took \(timeElapsed) ms")
