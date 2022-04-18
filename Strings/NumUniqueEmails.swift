import Foundation

class Solution {
    func numUniqueEmails(_ emails: [String]) -> Int {
        var simpleSet = Set<String>()

        for email in emails {
            var realMailArr = email.components(separatedBy: "@")
            var localName = ""
            for c in realMailArr[0] {
                if c == "+" {
                    break
                }
                
                if c == "." { continue }

                localName.append(c)
            }

            realMailArr[0] = localName
            simpleSet.insert(realMailArr.joined(separator: "@"))
        } 

        print(simpleSet)
        return simpleSet.count
    }
}

let solution = Solution()
print(solution.numUniqueEmails([
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
]))

print(solution.numUniqueEmails(["a@leetcode.com","b@leetcode.com","c@leetcode.com"]))

