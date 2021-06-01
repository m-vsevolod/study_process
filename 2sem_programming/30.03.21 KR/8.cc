void fix_list(BehaviorPattern* root) {
    if (root != NULL) {
        BehaviorPattern *current = root->next;
        BehaviorPattern *previous = root;
        root->prev = NULL;
    while (current != NULL) {
        current->prev = previous;
        previous = current;
        current = current->next;
        }
    }
}