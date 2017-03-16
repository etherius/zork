#include "Messages.h"

void ProtectionViolationMessage() {
    more_output("There appears before you a threatening figure clad all over");
    more_output("in heavy black armor.  His legs seem like the massive trunk");
    more_output("of the oak tree.  His broad shoulders and helmeted head loom");
    more_output("high over your own puny frame, and you realize that his powerful");
    more_output("arms could easily crush the very life from your body.  There");
    more_output("hangs from his belt a veritable arsenal of deadly weapons:");
    more_output("sword, mace, ball and chain, dagger, lance, and trident.");
    more_output("He speaks with a commanding voice:");
    more_output("");
    more_output("                    \"You shall not pass.\"");
    more_output("");
    more_output("As he grabs you by the neck all grows dim about you.");
}

void InitializationFailureMessage() {
    more_output("Suddenly a sinister, wraithlike figure appears before you,");
    more_output("seeming to float in the air.  In a low, sorrowful voice he says,");
    more_output("\"Alas, the very nature of the world has changed, and the dungeon");
    more_output("cannot be found.  All must now pass away.\"  Raising his oaken staff");
    more_output("in farewell, he fades into the spreading darkness.  In his place");
    more_output("appears a tastefully lettered sign reading:");
    more_output("");
    more_output("                       INITIALIZATION FAILURE");
    more_output("");
    more_output("The darkness becomes all encompassing, and your vision fails.");
}