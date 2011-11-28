//
//  ILLocalized.h
//
//  Created by ToKoRo on 2011-06-18.
//  Last Change: 2011-07-15.
//

#define ILLocalizedString( str ) NSLocalizedString( (str), nil )
#define LSTR( str ) ILLocalizedString( (str) )
#define ILLocalizedProperty( prop ) (prop) = NSLocalizedString( (prop), nil )
#define ILLocalizedButton( btn )  [(btn) setTitle:NSLocalizedString( (btn).titleLabel.text, nil ) forState:UIControlStateNormal]; \
                                  [(btn) setTitle:NSLocalizedString( (btn).titleLabel.text, nil ) forState:UIControlStateHighlighted]; \
                                  [(btn) setTitle:NSLocalizedString( (btn).titleLabel.text, nil ) forState:UIControlStateDisabled]; \
                                  [(btn) setTitle:NSLocalizedString( (btn).titleLabel.text, nil ) forState:UIControlStateSelected]
