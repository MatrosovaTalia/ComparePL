import Foundation

func fillGradientLine(arr: inout [UInt8], line: Int, w: Int, a: UInt8, b: UInt8) {
    let delta = b - a
    let offset = line * w
    for i in 0...(w-1) {
        let fraction = Float32(i) / Float32(w)
        arr[offset + i] = a + UInt8(Float32(delta) * fraction)
    }
}
func generateGrayGradient(_ h: Int,_ w: Int,_ a: UInt8,_ b: UInt8) -> [UInt8] {
    let size = w * h
    var arr = Array(repeating: UInt8(0), count: size)
    for i in 0...(h-1) {
        fillGradientLine(arr: &arr, line: i, w: w, a: a, b: b)
    }
    return arr
}


let h = 50
let w = 50
let a = UInt8(55)
let b = UInt8(233)

let startTime = Date().timeIntervalSinceReferenceDate
var result = generateGrayGradient(h, w, a, b)
let timeElapsed = (Date().timeIntervalSinceReferenceDate - startTime) * 1000
print("\(timeElapsed)")