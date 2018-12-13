/**
 * \brief Gets glucose reading
 * \author Graeme
 * 
 * This class sets returns glucose readings 
 *
 */

#ifndef GLUCOSEREADING_H
#define GLUCOSEREADING_H

class GlucoseReading
{
    public:
      /**
       * \brief Constructor
       * \param glucoseAmount a glucose rading
       *
       */
        GlucoseReading(const double glucoseAmount);

      /**
       * \brief Returns glucose amount
       * \return a glucose amount
       *
       */
        const double getAmount() const;
    private:
        const double amount;
};

#endif
