/**
 * Playing with Problems
 */
/**
 * play.png
 */
/**
 * You often hear software
 * engineers complain that “real
 * software work” has nothing to
 * do with solving algorithmic
 * problems. Why waste time,
 * they say, doing algorithms
 * when we would never use them?
 *
 * Sadly this complaint has some
 * truth to it but I think we
 * should still solve problems.
 * And I’ll tell you why – it
 * trains us to spend time
 * playing with and developing a
 * deep understanding of the
 * problem instead of jumping
 * into the first solution we
 * find.
 *
 * I have grown “through the
 * ranks” of our industry – from
 * a Junior Coder to Team
 * Leader, Project Leader, and
 * so on until my current
 * position as Head of
 * Engineering. Over the years I
 * have found that the worst
 * solutions and the biggest
 * waste of time came when I or
 * my developers rushed to
 * deliver solutions to without
 * truly understanding the
 * problem well. Hours, even
 * days, are wasted building
 * something that no one wants.
 * Then, to salvage the work
 * done, we often shoehorn the
 * solution into a limping,
 * somewhat-usable, delivery.
 *
 * On the other hand, anyone who
 * has spent time solving
 * algorithmic puzzles develops
 * a feel for playing with
 * problems. We know how
 * rewarding it can be to see a
 * difficult puzzle break down
 * and become tractable.
 *
 * You disagree? You’re not
 * sure? Well, let’s see what I
 * mean by looking at an
 * example. We take the classic
 * problem:
 */
/**
 * *__.
 * *Given two strings, how would
 * you check if one is the
 * rotation of the other?*
 *   _For example “abc” and “bca”
 *   are rotations of each other_
 * .__*
 */
/**
 * *_Rushing to a Solution_*
 */
/**
 * If we rushed to a solution we
 * would rotate the first string
 * and compare it with the
 * second like so:
 */
#include <string>
#include <algorithm>

bool is_rotated(std::string s1, std::string s2) {
    if(s1.length() != s2.length()) return false;
    for(int i = 0;i < s1.length();i++) {
        std::rotate(s1.begin(), s1.begin()+1, s1.end());
        if(s1 == s2) return true;
    }
    return false;
}

/**
 * Now this solution works fine
 * and if we don’t like it we
 * can try further improving the
 * solution – perhaps using a
 * modulus index instead of
 * performing a rotating in the
 * loop, perhaps optimizing the
 * rotation itself and so on.
 */

/**
 * *_Playing with the Problem_*
 */
/**
 * However, instead of doing
 * this, let’s try playing with
 * the problem a bit more. Just
 * try out the problem and take
 * a look at a few rotated
 * strings to see if any ideas
 * jump out.
 *
 *   abcdef      i like programming
 *   fabcde      gi like programmin
 *   efabcd      ngi like programmi
 *   dfabcd      ingi like programm
 *   ...         ...
 *
 * Playing around like this, to
 * me it ‘feels like’, there is
 * a link between the first and
 * the last character of the
 * string. They are “tied
 * together” somehow:
 *
 *   abcde.f...a
 *   i like programming...i
 *   ab..a
 *
 * At least, they aren’t as far
 * apart as they initially
 * appear. Once we perform a
 * rotation, we see the same
 * “link” between other
 * characters.
 *
 *   abcde.f...a...b...c...
 *   I like programming...i...l...i...k...e...
 *
 * So what would it look like if
 * just went ahead and stuck the
 * string to itself again?
 *
 *   abcdefabcdef
 *   i like programmingi like programming
 *
 * If we look at this carefully,
 * and look at all possible
 * rotations, we see that just
 * sticking them together like
 * this has given us a string
 * with all possible rotations
 * embedded!
 *
 * Seeing this, our solution can
 * completely change. All we
 * need to do is stick the
 * string in front of itself and
 * see if the second string is a
 * substring. Substrings are
 * something we are much more
 * familiar with. So the
 * algorithm becomes:
 */
bool is_rotated2(std::string s1, std::string s2) {
    if(s1.length() != s2.length()) return false;
    return (s1 + s1).find(s2) != std::string::npos;
}

/**
 * *_Conclusion_*
 */
/**
 * From our initial O(n^2)
 * algorithm we’ve now got a
 * possible O(n) solution that
 * is much simpler! In this way,
 * playing with the problem
 * often can lead to a vastly
 * improved solutions. This is
 * why I feel doing algorithmic
 * puzzles are good practice for
 * real world software issues.
 */

int main(int argc, char* argv[]) {
    if(argc != 3) return -1;
    return (is_rotated2(argv[1], argv[2]) ? 0 : 1);
}

