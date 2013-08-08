#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IRSignal.h"

typedef NS_ENUM(NSUInteger, IRAnimatingType) {
    IRAnimatingTypeInsert = 1,
    IRAnimatingTypeDelete = 2
};

@protocol IRAnimatingControllerDelegate <NSObject>

@optional
- (void)controller:(id)controller
   didChangeObject:(id)object
       atIndexPath:(NSIndexPath *)indexPath
     forChangeType:(IRAnimatingType)type
      newIndexPath:(NSIndexPath *)newIndexPath;

// TODO do we need this?
- (void)controllerDidChangeContent:(id)controller;

@end

@interface IRSignals : NSObject<UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, assign) id<IRAnimatingControllerDelegate> delegate;
- (id)objectAtIndex:(NSUInteger)index;
- (NSData*)data;
- (void)loadFromData: (NSData*)data;
- (void)loadFromStandardUserDefaultsKey:(NSString*)key;
- (void)saveToStandardUserDefaultsWithKey:(NSString*)key;
- (NSString*)JSONRepresentation;
- (void)sendSequentiallyWithCompletion:(void (^)(NSError *error))completion;

#pragma mark - Key Value Coding - Mutable Unordered Accessors

- (NSArray*) signals;
- (NSUInteger) countOfSignals;
- (NSEnumerator*)enumeratorOfSignals;
- (IRSignal*)memberOfSignals:(IRSignal *)object;
- (void)addSignalsObject:(IRSignal *)object;
- (void)removeSignalsObject:(IRSignal *)object;

@end