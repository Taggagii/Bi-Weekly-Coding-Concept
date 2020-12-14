# Binary Trees

[](https://jbt.github.io/markdown-editor/) 

### Introduction
 [Binary Trees](https://en.wikipedia.org/wiki/Binary_tree) are a data structure containing nodes; these nodes branch off to two other nodes — one to the left and one to the right.
 
### Vocabulary
<img align="right" src = "https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg" alt = "Labelled Binary Tree Diagram" width = 400 >

__Root__: The first node activitated from which all other nodes ancestrally branched<br/>
__Level__: The distance a line of nodes is from the root<br/>
__Parent__: The node by which two other nodes — left and right — may connect.<br/>
__Child__: The node functioning as, either, the left or right branch of an above node<br/>
__Siblings__: Nodes which branch from the same parent<br/>
__Generation__: The nodes which inhabiate a specific level<br/>
__Sub-tree__: A tree branching from a above tree<br/>
__Leaves / Leaf__: A node with no children nodes<br/>


### General Rules of Binary Trees
1. When moving left or right into a binary tree:\
         - The left movement is equal to `2 * parentValue + 1`\
         - The right movement is equal to `2 * parentValue + 2`
2. The number of branches at a specific level is `2ˡᵉᵛᵉˡ`
3. The sum of branches of a specific height is `2ʰᵉᶦᵍʰᵗ - 1`
