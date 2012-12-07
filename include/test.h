#ifndef TEST_H
#define TEST_H

class Test {
public:
    /** Default constructor */
    Test();
    /** Default destructor */
    virtual ~Test();
    /** Copy constructor
     *  \param other Object to copy from
     */
    Test(const Test& other);
    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    Test& operator=(const Test& other);
    /** Access counter
     * \return The current value of counter
     */
    unsigned int getCounter() { return counter; }
    /** Set counter
     * \param value New value to set
     */
    void setCounter(unsigned int value) { counter = value; }
protected:
private:
    unsigned int counter; //!< Member variable "counter"
};

#endif // TEST_H
