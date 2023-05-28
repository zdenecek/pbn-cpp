#ifndef UTILS_OBSERVER_HPP_
#define UTILS_OBSERVER_HPP_

/*
    This file contains a few helper functions for creating observer_ptr's.
    The observer_ptr is a pointer that does not own the object it points to.
    It is used to pass pointers to objects that are owned by other objects.
    The syntax is used as to not use * and & operators.
*/


/**
 * @brief A pointer that does not own the object it points to.
*/
template <typename T>
using observer_ptr = T*;

/**
 * @brief Creates an observer_ptr from a raw pointer.
*/
template <typename T>
auto make_observer(T* ptr) -> observer_ptr<T> {
    return ptr;
}

/**
 * @brief Creates an observer_ptr from a refrerence.
*/
template <typename T>
auto make_observer(T& ptr) -> observer_ptr<T> {
    return &ptr;
}

/**
 * @brief Creates an observer_ptr from a const reference.
*/
template <typename T>
auto make_observer(const T& ptr) -> observer_ptr<T> {
    return &ptr;
}

/**
 * @brief Creates an observer_ptr from a unique_ptr reference.
*/
template <typename T>
auto make_observer(std::unique_ptr<T>& ptr) -> observer_ptr<T> {
    return ptr.get();
}

/**
 * @brief Creates an observer_ptr from a unique_ptr const reference.
*/
template <typename T>
auto make_observer(const std::unique_ptr<T>& ptr) -> observer_ptr<T> {
    return ptr.get();
}

/**
 * @brief Creates an observer_ptr from a unique_ptr reference.
*/
template <typename T>
auto ptr_to_observer(std::unique_ptr<T>& ptr) -> observer_ptr<T> {
    return ptr.get();
}

/**
 * @brief Creates an observer_ptr from a unique_ptr const reference.
*/
template <typename T>
auto ptr_to_observer(const std::unique_ptr<T>& ptr) -> observer_ptr<T> {
    return ptr.get();
}

#endif // UTILS_OBSERVER_HPP_
