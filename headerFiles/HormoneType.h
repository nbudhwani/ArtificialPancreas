#ifndef HORMONETYPE_H
#define HORMONETYPE_H

/// Types of insulin.
enum class HormoneType {
	/// Long term acting insulin
	BASAL_INSULIN,
	/// Short term acting insulin for taking after meals
	BOLUS_INSULIN, 
	/// Hormone to raise glucose levels. Counteracts insulin during hypoglycemic emergencies.
	GLUCAGON 
};

#endif
