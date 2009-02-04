/*
 * Rajarshi Guha <rajarshi@presidency.com>
 * 2/11/04
 *
 * Example of finding the MCSS for two molecules and 
 * displaying the 2D structures (hydrogen excluded) with
 * the MCSS highlighted
 *
 * Updated 5/04/06 - synced with the latest CDK
 * Updated 9/07/06 - synced with the latest CDK
 */
import java.io.File;
import java.io.FileReader;
import java.util.List;
import java.util.Iterator;
import java.util.Vector;
import java.util.HashSet;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import org.openscience.cdk.exception.CDKException;
import org.openscience.cdk.CDKConstants;
import org.openscience.cdk.interfaces.IAtom;
import org.openscience.cdk.interfaces.IBond;
import org.openscience.cdk.interfaces.IAtomContainer;
import org.openscience.cdk.interfaces.IChemFile;
import org.openscience.cdk.ChemFile;
import org.openscience.cdk.interfaces.IChemObject;
import org.openscience.cdk.interfaces.IMolecule;
import org.openscience.cdk.DefaultChemObjectBuilder;
import org.openscience.cdk.io.IChemObjectReader;
import org.openscience.cdk.io.ReaderFactory;
import org.openscience.cdk.tools.manipulator.ChemFileManipulator;
import org.openscience.cdk.tools.manipulator.AtomContainerManipulator;

import org.openscience.cdk.isomorphism.mcss.RMap;
import org.openscience.cdk.isomorphism.UniversalIsomorphismTester;

import org.openscience.cdk.layout.StructureDiagramGenerator;
import org.openscience.cdk.geometry.GeometryTools;
import org.openscience.cdk.renderer.Renderer2D;
import org.openscience.cdk.renderer.Renderer2DModel;

import org.openscience.cdk.tools.LoggingTool;

class displaySubstructure extends JPanel
{
    IAtomContainer haystack;

    Renderer2DModel r2dm;
    Renderer2D renderer;

    public displaySubstructure(IAtomContainer haystack, IAtomContainer needle)
    {
        r2dm = new Renderer2DModel();
        renderer = new Renderer2D(r2dm);
        Dimension screenSize = new Dimension(300, 300);
        setPreferredSize(screenSize);
        r2dm.setBackgroundDimension(screenSize); 
        setBackground(r2dm.getBackColor());

        this.haystack = haystack;

        try
        {
            r2dm.setDrawNumbers(false);
            r2dm.setUseAntiAliasing(true);
            r2dm.setShowAromaticity(true);
            r2dm.setColorAtomsByType(false);
            //r2dm.setHighlightColor(Color.blue); 
	    r2dm.setSelectedPartColor(Color.blue);

            r2dm.setSelectedPart( needle );

            GeometryTools.translateAllPositive(this.haystack);
            GeometryTools.scaleMolecule(this.haystack, getPreferredSize(), 0.8);			
            GeometryTools.center(this.haystack, getPreferredSize());
        }
        catch(Exception exc)
        {
            exc.printStackTrace();		
        }
    }

    public void paint(Graphics g)
    {
        super.paint(g);
        renderer.paintMolecule(this.haystack, (Graphics2D)g, false, true);
    }

}
        
    

public class simplemcss {
    public static IAtomContainer getneedle(IAtomContainer a, IAtomContainer q) {
        IAtomContainer needle = DefaultChemObjectBuilder.getInstance().newAtomContainer();
        Vector idlist = new Vector();

	List l = null;
	try {
	    l = UniversalIsomorphismTester.getSubgraphMaps(a, q);
	} catch (CDKException cdke) {
	    cdke.printStackTrace();
	}
        System.out.println("Number of matched subgraphs = "+l.size());
        for (int j = 0; j < 1; j++) {
            List maplist = (List)l.get(j);
            for (Iterator i = maplist.iterator(); i.hasNext(); ) {
                RMap rmap = (RMap)i.next();
                idlist.add( new Integer( rmap.getId1() ) );
            }
        }
        HashSet hs = new HashSet(idlist);
        for (Iterator i = hs.iterator(); i.hasNext();) {
            needle.addBond( a.getBondAt( ((Integer)i.next()).intValue() ) );
        }
        return needle;
    }

    public static void main(String[] args) {

        Vector v = new Vector();
        LoggingTool logger = new LoggingTool(true);

        try {
            int i = 0;
            int j = 0;

            // load the molecule and generate 2D coordinates
            for (i = 0; i < args.length; i++) {
                File input = new File(args[i]);
                IChemObjectReader reader = new ReaderFactory().createReader(new FileReader(input));
                IChemFile content = (IChemFile)reader.read((IChemObject)new ChemFile());
                IAtomContainer[] c = ChemFileManipulator.getAllAtomContainers(content);

                // we should do this loop in case we have files
                // that contain multiple molecules
                // for this case we assume that each file has 1 molecule
                StructureDiagramGenerator sdg = new StructureDiagramGenerator();
                sdg.setMolecule((IMolecule)c[0]);
                sdg.generateCoordinates();
                
                // get rid of hydrogens so that the MCSS algo does not consider them
                IAtomContainer mol = (IAtomContainer)sdg.getMolecule();
		mol = AtomContainerManipulator.removeHydrogens(mol);
                v.add(mol);
            }

            /* This is the key section */
            List mcsslist = UniversalIsomorphismTester.getOverlaps( (IAtomContainer)v.get(0), (IAtomContainer)v.get(1));
            System.out.println("Number of overlaps = "+mcsslist.size());

            int maxmcss = -9999999;
            IAtomContainer maxac = null;
            for (i = 0; i < mcsslist.size(); i++){
                IAtomContainer a = (IAtomContainer)mcsslist.get(i);
                if (a.getAtomCount() > maxmcss) {
                    maxmcss = a.getAtomCount();
                    maxac = a;
                }
            }

            IAtomContainer ac1 = (IAtomContainer)v.get(0);
            IAtomContainer ac2 = (IAtomContainer)v.get(1);

            // show original structs with mcss hilighted
            IAtomContainer n1 = getneedle(ac1, maxac);
            IAtomContainer n2 = getneedle(ac2, maxac);
            displaySubstructure dss1 = new displaySubstructure(
                    ac1, n1);
            displaySubstructure dss2 = new displaySubstructure(
                    ac2, n2);

            JFrame frame = new JFrame("Maxmimum Common Substructure (Highlighted)");
            JPanel pane = new JPanel(new GridBagLayout());
            GridBagConstraints gbc = new GridBagConstraints();
            JLabel l1 = new JLabel(args[0],SwingConstants.CENTER);
            JLabel l2 = new JLabel(args[1],SwingConstants.CENTER);
            gbc.fill = GridBagConstraints.HORIZONTAL;
            gbc.gridx = 0; gbc.gridy = 0;
            pane.add(l1,gbc);
            gbc.gridx = 1; gbc.gridy = 0;
            pane.add(l2,gbc);
            gbc.gridx = 0; gbc.gridy = 1; 
            pane.add(dss1,gbc);
            gbc.gridx = 1; gbc.gridy = 1; 
            pane.add(dss2,gbc);
            frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            frame.getContentPane().add(pane);
            frame.pack();
            frame.setVisible(true);

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

