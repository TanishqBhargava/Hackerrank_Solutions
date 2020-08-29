import java.util.*

val maxNum = 1700
val bitList = (0..31).map { 1U shl it }
fun iterateIt(bitArray: Array<UInt>, cnt: Int = 0): Int {
    val resultBitArray= Array(maxNum){0U}
    for (p in 0 until maxNum) {
        if (bitArray[p]>0U) {
           for (i in bitList.indices) {
               val a = bitArray[p] and bitList[i]
               if (a>0U && (p!=0 || i!=0)) {
                   for (p1 in p until maxNum) {
                       if (bitArray[p1] > 0U) {
                           val np = p1-p
                           val np1 = np-1
                           val minNum = bitArray[p1] shr i
                           resultBitArray[np] = resultBitArray[np] or minNum
                           if (np1>=0 && i>0) {
                               resultBitArray[np1] = resultBitArray[np1] or (bitArray[p1] shl (32 - i))
                           }
                       }
                   }
               }
           }
        }
       if (resultBitArray[0] and 2U >0U) {
            for (p1 in maxNum-1 downTo 0) {
                if (resultBitArray[p1]>0U) {
                    for (i in bitList.size-1 downTo 0) {
                        if ((resultBitArray[p1] and bitList[i])>0U) {
                            val maxNum = (p1 shl 5) or i
                            return maxNum + cnt +1
                        }
                    }
                }
            }
        }
    }
    val cd = checkDiv(resultBitArray)
    if (cd>0) return cd+cnt+1
    return iterateIt(resultBitArray, cnt+1)
}

fun checkDiv(resultBitArray: Array<UInt>): Int {
    for (p1 in 0 until maxNum) {
        if (resultBitArray[p1]>0U) {
            for (i in bitList.indices) {
                if ((resultBitArray[p1] and bitList[i])>0U && (p1!=0 || i!=0)) {
                    val minNum = (p1 shl 5) or i
                    var x = 0
                    var maxP =0
                    var maxI =0
                    for (p2 in 0 until maxNum) {
                        for (i1 in bitList.indices) {
                            if ((p2!=0 || i1!=0)) {
                                x++
                                if ((resultBitArray[p2] and bitList[i1])>0U) {
                                    if (x % minNum == 0) {
                                        maxP = p2
                                        maxI = i1
                                    } else {
                                        return 0
                                    }
                                }
                            }
                        }
                    }
                    return ((maxP shl 5) or maxI)/minNum
                }
            }
        }
    }
    return 0
}

fun arrayToBitArray(items: Array<Int>): Array<UInt> {
    val itSetArray = Array(maxNum){0U}
    items.forEach { i ->
        val p = i shr 5
        val n = bitList[i and 31]
        itSetArray[p]=itSetArray[p] or n
    }
   return itSetArray
}

fun main(args: Array<String>) {
 val scan = Scanner(System.`in`)

 val aCount = scan.nextLine().trim().toInt()

 val a = scan.nextLine().split(" ").map{ it.trim().toInt() }.distinct().toTypedArray()
 
 val result = if (a.size == 1) 1 else iterateIt(arrayToBitArray(a))

 println(result)
}
